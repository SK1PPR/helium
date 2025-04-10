# Helium

Helium is a toy project that converts photos and videos to ASCII art and displays them on the terminal

## Build instructions

The project requires `opencv` and `opencv` devel to be present

- `cmake -S . -B <build_dir>`
-  `cmake --build <build_dir>`

## Run

### For images
`<build_dir>/helium --img <path_to_img>`

### For videos
- For colored video: `<build_dr>/helium --vid <path_to_vid>`
- For normal ascii video: `<build_dir>/helium --vid -b <path_to_vid>`

## To-do :

- [x] Add colors
- [ ] Add multi-threading for faster processing


## Future scope :

- Add ability to convert the audio to 8-bit