# Macro Keyboard
[![](/.media/final1.min.jpg)](/.media/final1.jpg)
A 15-key Arduino-based, mechanical macro keyboard powered by the Seeeduino XIAO.

# Fork
I made this forked version because I had no use for the bluetooth functionality, and wanted to keep it simple and sweet. I decided to use a different microcontroller than the original model, as the Seeeduino XIAO is faster, smaller, and connects using USB-C instead of the default Micro-B that the Pro Micro has.
# <sub><sup>(even more)</sup></sub> Glamour shots
[![](/.media/final2.min.jpg)](/.media/final2.jpg)
[![](/.media/final3.min.jpg)](/.media/final3.jpg)
[![](/.media/final4.min.jpg)](/.media/final4.jpg)

# How it works
The keyboard uses a key matrix which maps the physical buttons to the keys <kbd>F10</kbd> to <kbd>F24</kbd>. These can afterwards be mapped to for example, execute a script. I used "Kwin Custom Shortcuts" for this, as that allows you to execute a different option based on the focused application. This also allows you to directly run a [bash] script, so you can script exactly what each button will do.  
While untested, you most likely can use AutoHotKey on windows for the same functionality.

The keys are set up like this:
| <kbd>F10</kbd> <sub><sup>203</sup></sub> | <kbd>F11</kbd> <sub><sup>204</sup></sub> | <kbd>F12</kbd> <sub><sup>205</sup></sub> | <kbd>F13</kbd> <sub><sup>240</sup></sub> | <kbd>F14</kbd> <sub><sup>241</sup></sub> |
|-----|-----|-----|-----|-----|
| <kbd>F15</kbd> <sub><sup>242</sup></sub> | <kbd>F16</kbd> <sub><sup>243</sup></sub> | <kbd>F17</kbd> <sub><sup>244</sup></sub> | <kbd>F18</kbd> <sub><sup>245</sup></sub> | <kbd>F19</kbd> <sub><sup>246</sup></sub> |
| <kbd>F20</kbd> <sub><sup>247</sup></sub> | <kbd>F21</kbd> <sub><sup>248</sup></sub> | <kbd>F22</kbd> <sub><sup>249</sup></sub> | <kbd>F23</kbd> <sub><sup>250</sup></sub> | <kbd>F24</kbd> <sub><sup>251</sup></sub> |

# Folder structure
```
├── src      # source code for the arduino
└── stl      # STL files for the case and the lid
└── cddx     # CDDX files for the circuit
```

# Bill of materials
| Item | Description |
| ------ | ------ |
| 15 Cherry MX Mechanical switches | I used AliExpress, but anything should work here |
| Seeeduino XIAO | The main microcontroller powering it all. Bought from [Seeed Studio Bazaar](https://www.seeedstudio.com/Seeeduino-XIAO-Arduino-Microcontroller-SAMD21-Cortex-M0+-p-4426.html) |
| Diodes | |
| Keycaps | I bought some clear keycaps from AliExpress which worked flawlessly |
| 4 x anti-slip pads | Need to fit into the circular cut-outs on the bottom of the case. Help keep it steady on the desk and compensate for slight warping from 3D printing. I used transparent self-adhesive ones, but you can stick them on with anything |

# The layout
The original STL had space for all the required components used. Because I did not implement any bluetooth functionality, the box will be quite empty inside; if not for the microcontroller and cables.  

# STL
This forked version does not have a custom modified version of the STL as I personally do not have the know-how to model such thing. Because of this, you will have to remove a support piece placed at the USB-C connector port, and there also will be some empty gaps (where the power switch was supposed to be, for example). I do wish to modify the STL at some point in the future to make it work perfectly with this version, however.

# Circuit Diagram
The CDDX files can be found in the `cddx` folder.  
Wiring follows a grid matrix layout. These are then wired to the corresponding pins on the XIAO.
![](.media/circuit.svg)

# Xmodmap
On unix based systems you may need to add a .Xmodmap to your home directory as otherwise the F13 to F24 keys may not be recognized correctly by some software. I've added an [example .Xmodmap](.Xmodmap) in this repo for those specific keybindings.