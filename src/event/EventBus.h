/*
    SchumakerTeam
    Hudson Schumaker
*/

#pragma once
#include "Event.h"

class IEventCallback {
private:
    virtual void call(Event& e) = 0;

public:
    virtual ~IEventCallback() = default;

    void execute(Event& e) {
        call(e);
    }
};

template <typename TOwner, typename TEvent>
class EventCallback final : public IEventCallback {
private:
    typedef void (TOwner::* CallbackFunction)(TEvent&);

    TOwner* ownerInstance;
    CallbackFunction callbackFunction;

    virtual void call(Event& e) override {
        std::invoke(callbackFunction, ownerInstance, static_cast<TEvent&>(e));
    }

public:
    EventCallback(TOwner* ownerInstance, CallbackFunction callbackFunction) {
        this->ownerInstance = ownerInstance;
        this->callbackFunction = callbackFunction;
    }

    virtual ~EventCallback() override = default;
};

typedef std::list<std::unique_ptr<IEventCallback>> HandlerList;

class EventBus {
private:
    inline static EventBus* instance;
    std::map<std::type_index, std::unique_ptr<HandlerList>> subscribers;

    EventBus() {}
    ~EventBus() {}

public:
    static EventBus* getInstance() {
        if (instance == nullptr) {
            instance = new EventBus();
        }

        return instance;
    }

    void reset() {
        subscribers.clear();
    }

    template <typename TEvent, typename TOwner>
    void subscribeToEvent(TOwner* ownerInstance, void (TOwner::* callbackFunction)(TEvent&)) {
        if (!subscribers[typeid(TEvent)].get()) {
            subscribers[typeid(TEvent)] = std::make_unique<HandlerList>();
        }
        auto subscriber = std::make_unique<EventCallback<TOwner, TEvent>>(ownerInstance, callbackFunction);
        subscribers[typeid(TEvent)]->push_back(std::move(subscriber));
    }

    template <typename TEvent, typename ...TArgs>
    void emitEvent(TArgs&& ...args) {
        auto handlers = subscribers[typeid(TEvent)].get();
        if (handlers) {
            for (auto it = handlers->begin(); it != handlers->end(); it++) {
                auto handler = it->get();
                TEvent event(std::forward<TArgs>(args)...);
                handler->execute(event);
            }
        }
    }
};