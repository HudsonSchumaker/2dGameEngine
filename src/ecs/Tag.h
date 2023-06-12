/*
	SchumakerTeam
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
enum class Tag {
    standard = 0,
    background = 1,
    tile = 2,
    enemy = 3,
    player = 4,
    bullet = 5,
    ui = 6
};

class Tags final {
public:
    static short getLayer(Tag tag) {
        return (short)tag;
    }

    static Tag getTag(short id) {
        return static_cast<Tag>(id);
    }
};
