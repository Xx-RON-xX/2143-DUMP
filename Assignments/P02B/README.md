**Player Class**:
- **Data**:
  - `name`
  - `score`
  - `dice_set`: Array of Dice objects
  - `player_stats`
  
- **Actions**:
  - `roll_dice()`: Roll the dice for the player.
  - `get_score()`: Retrieve the current score.
  - `update_score(points)`: Update the player’s score after each roll.

- **Relationships**:
  - A Player **HAS-A** Dice (composition).
  - A Player **IS-A** participant in the game.

**Game Class**:
- **Data**:
  - `players`
  - `rules`
  - `current_round`
  
- **Actions**:
  - `startgame()`: Starts the game.
  - `endgame()`: Ends the game.
  - `getwinner()`: Take final score and retrieve the winner.

- **Relationships**:
  - A Game **HAS-A** Player (composition).

**Dice Class**:
- **Data**:
  - `sides`
  - `currentValue`
  
- **Actions**:
  - `roll()`: Generates a value for the dice.
  - `get_value()`: Takes and stores the value of the dice.

- **Relationships**:

**Knucklebones Class**:
- **Data**:
  - `board`
  - `knucklebones_rules`
  
- **Actions**:
  - `startround()`: Begins a round within the game.
  - `endround()`: Ends a round to start a new rounds or end the game.
  - `calculatewinner()`: Takes scores to calculate winner of the round.

- **Relationships**:
  - A Knucklebone **IS-A** Game
  - A Knucklebone **HAS-A** Player
  - A Knucklebone **HAS-A** Dice
 
**Chat Class**:
- **Data**:
  - `mess_output`
  - `mess_input`
  - `chatbox`: Array or vector of previous messages
  
- **Actions**:
  - `inputMess()`: Allows player to type in message.
  - `get_message()`: Retrieve the Player Message.
  - `updatechat(mess_output)`: Show the new message in the chatbox.

- **Relationships**:
  - A Chat **HAS-A** Players.

**KEYWORDS:**

- chat (**necessary**)
- coins (**wishful**)
- first name (**necessary**)
- high score (**necessary**)
- last name (**necessary**)
- leaderboard (**necessary**)
- ranks (**possible**)
- messaging (**necessary**)
- player stats (**necessary**)
- score (**necessary**)
- streak (**wishful**)
- team stats (**wishful**)
- teams (**possible**)
- userid (**necessary**)
- winner (**necessary**)
- player avatar (**possible**)
