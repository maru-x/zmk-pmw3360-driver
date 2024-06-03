zephyr_include_directories(src)

zephyr_library()

zephyr_library_sources(src/pmw3610.c)
zephyr_library_sources(src/pmw3610_priv.c)
