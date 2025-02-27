
# Planning

## First step `validate the map`

* validate the map extention
* read the map and check it's rectangle
* use the flood fill to check if the player has access to all collectibles, door, and if the map is surrounded by walls (no exit execpt the door)
ensure that the map is composed of the following:

| char | diplays | Description |
| ---- | ------- | ----------- |
| 0 | for an empty space | --- |
| 1 | for a wall | the map sould be sourrended by walls |
| C | for collectible | at least one |
| E | for a map exit | only one |
| P | for the player | only one |
    

Potential bug:

	1- new lines at the end of a file
	2- a string(s) after new line(s)