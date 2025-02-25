
# Planning

## First step `validate the map`

* validate the map extention
* read the map and check it's rectangle
* use the flood fill to check if the player has access to all collectibles, door, and if the map is surrounded by walls (no exit execpt the door)
=> ensure that the map is composed of the following:
| char | diplays | Description |
| ---- | ------- | ----------- |

		| 0 | for an empty space | ,
		| 1 for a wall,
		| C for collectible,
		| E for a map exit,
		| P for the player
    