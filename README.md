# Dodoi Engine 

### Components
    Audio       : Holds data for audio files to be played.
    Animation   : Holds data for animated sprites.
    Box         : Holds data for drawing boxes on the screen.
    BoxCollider : Holds data for collision detection. 
    Button      : Holds data for button functionality.
    CameraFollow: Holds data for camera movement.
    Circle      : Holds data for drawing circles on the screen. 
    Controller  : Holds data for joystick controller input.
    Health      : Holds data for entity health.
    Line        : Holds data for drawing lines on the screen.
    Projectile  : Holds data for projectiles.
    Radar       : Holds data for radius-based collision detection.
    RigidBody   : Holds data for entity velocity.
    Sprite      : Holds data for drawing sprites on the screen.
    TextLabel   : Holds data for drawing text on the screen.
    Transform   : Holds data for entity position.
    Waypoint    : Holds data for waypoint navigation.
### Systems
    AnimationSystem: Updates animations based on time and state.
	CameraMovementSystem: Moves the camera based on the followed entity's position.
	CollisionSystem: Checks for collisions between entities.
	ControllerSystem: Handles joystick controller input.
	DamageSystem: Updates entity health based on damage taken.
	GuiUpdateSystem: Updates the GUI based on game state.
	MouseSystem: Handles mouse input.
	MovementSystem: Updates entity positions based on their velocity.
	PrimitiveRenderSystem: Draws primitive shapes like boxes and circles.
	ProjectilesEmitterSystem: Emits projectiles based on game state.
	ProjectileLifecycleSystem: Handles the lifecycle of projectiles.	
	RadarSystem: Checks for entities within a certain radius.
	RenderColliderSystem: Draws colliders for debugging purposes.
	RenderSystem: Draws entities on the screen.
	RenderTextSystem: Draws text on the screen.
	WaypointNavigationSystem: Moves entities along waypoints.
