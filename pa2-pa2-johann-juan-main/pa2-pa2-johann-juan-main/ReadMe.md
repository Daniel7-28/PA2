# PA2: Rock, Paper, Scissors: The Game

## Description
When compiled and run, the base game has two Areas and two types of Enemies available. To enter the game, you press any
key, and the Player will be placed in the first area. To move, use the W (up), A (left), S (down) or D (left) keys. To move on to the second area, you must battle and beat all three enemies found in Area One. You fight enemies by colliding
with them and beating them at Rock, Paper, Scissors. To win the game, you must beat all enemies in Area Two.

## Specs
Specification that had should be done to this project

### Phase 1 
The specs for this phase will act as a warm-up.
• Walking Patterns: Change the walking patterns of the enemies. Currently, the walking pattern forms a square in a clockwise fashion. Changing
the direction or walking pattern shape suffices.
• Pause State: Create a Pause State for the game. Pressing the ‘p’ key will trigger this pause state, and pressing it again will exit out of it. You should not be able to trigger this state outside of the Battle State or the Overworld State.
• Heads-Up Display (HUD): Display Area name, Player health, and current living Enemies in Area in the Overworld State.
• DEBUG Keys: Pressing the ‘h’ key will reset the health of the Player to full health and pressing the ‘r’ key will respawn all defeated enemies on the Overworld.

### Phase 2 
The focus of this will be to work with existing classes in a more complex way and refactoring.
• Loading State: Create a loading screen to buffer between major state changes. That is to say, this Loading Screen should appear for two to three seconds (long enough to be apparent) between Title State, Overworld State, Battle State and Area changes. NOTE: This state should not appeared when triggering the Pause State. That is to say, the transition between Overworld State and Pause State, and Battle State and Pause State should be immediate.
• Refactor Entity, Player and Enemy Classes: Refactor the Entity class so it only maintains the Overworld coordinates and Overworld sprite
attributes, and all functions associated with ticking and rendering an Entity on the Overworld. That is to say, there should be no attributes or functions alluding to fighting within the Entity class. These mechanics can either be moved directly into the Player and Enemy classes to maintain their fighting characteristics, or preferably, be contained within their own abstract class or interface. 
• Create (Static) Entities: Using your refactored Entity class, add instances of static entities to the map. These entities should not move, or be interactable. However, the Player should not be able to move through them when they collide with said Entity. Examples of possible static entities would be a tree or a building.

### Phase 3 
The focus of this phase will be to implement Friendly and Boss Entities.
• Friend: Implement a Friend class. This class must inherit from the Entity class. The Player can interact with a Friend by pressing the ‘e’ key when colliding with the Friend. When doing so, text denoting speech from the Friend must pop up on the screen or some other indicator of interaction should happen. Text that pops up on the screen should only appear for a fixed amount of time or should disappear after pressing any key. Friends must move in a pattern as Enemies do. However, because Friends are not fightable, they should not have health nor should they have base damage. You must have at least one instance of a Friend in your game.
• Boss: Implement a Boss class. This class must inherit from the Enemy class. Bosses appear in an Area after all other Enemies of that area are defeated. A Boss Battle must have at least two phases. That is to say, you must deplete the Boss’s health bar twice in order to beat them. Defeating a Boss moves the Player to the next Area or a Win State if there are no remaining Areas. You must have at least one Boss instance per Area of the game.