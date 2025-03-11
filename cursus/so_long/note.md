
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

# MLX
### Create Window:

> `void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)`
>> create a new window of size_x*size_y with a title.

> `int mlx_clear_window(void *mlx_ptr, void *win_ptr)`
>> clear a window (black).

> `int mlx_destroy_window(void *mlx_ptr, void *win_ptr)`
>> destroy a window

### Draw inside a window:

> `int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color)`
>> draw a pixel in the window win_ptr using (x, y), The origin (0,0) is the up‐per left corner of the window

> `int mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string )`
>> display the given string in the window using (x, y)

### Manioulating images

> `void *mlx_new_image(void *mlx_ptr, int width, int height)`
>> create a new image

> `char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian)`
>>

> `int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y)`
>>

> `unsigned int mlx_get_color_value(void *mlx_ptr, int color)`
>>

> `void *mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height)`
>>

> `void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height)`
>>

> `int mlx_destroy_image(void *mlx_ptr, void *img_ptr)`
>> 