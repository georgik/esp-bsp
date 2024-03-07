# BSP: Display example

Vanilla example with BSP

## Build

```
idf.py -D SDKCONFIG_DEFAULTS=sdkconfig.bsp.esp32_p4_function_ev_board build
```


## Simulate

```
idf.py uf2
```

Then open the directory with VS Code and lauch Wokwi simulator