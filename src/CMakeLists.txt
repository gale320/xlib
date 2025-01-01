include_directories(xlib xmem xutil)
file(GLOB SRC ./xlib/*.c ./xutil/*.c ./xmem/*.c)
add_library(xlib SHARED ${SRC})