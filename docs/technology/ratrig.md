---
layout: default
title: RatRig Vcore 50cm 
parent: Technology
has_children: false
permalink: /docs/technologies/ratrig
---
# RatRig

Useful information for operation and maintenance of our Rat Rig 50x50x50.

### Useful Links
1. [Rat Rig V-Core3.1 Details](https://docs.ratrig.com/product-details/v-core3-1)

## Sending print to Rat rig
### SUPERSLICER SETUP
1. Download latest release of Super Slicer [Download](https://github.com/supermerill/SuperSlicer/releases)
2. Set up printer as RatRig-V-Core-3-500
3. Set the filament to PETG / PLA
4. Go to printer settings and change following fan speeds on expert mode

| Setting  | value |
| ----------------- | -- |
| Bridges fan speed    | 40% |
| Max fan speed     | 40% |

### RAT RIG SETUP
Connecting to Rat OS network on your computer.
1. Go to the WiFi settings on your computer and connect to **RatOS**
 
| Wifi       | RatOS        |
| ---------- | ------------ |
| Password   | raspberry    |

2. Next, on the internet browser window type in following IP address
192.168.50.1
3. You should be now connected to the Rat Rig console on your browser.
4. Upload the Gcode and Print !

## RatRig Website
Once connected to the website you will find different tabs with information about the printer/print.  
1. The first thing that will open is the main dashboard

[![Main Dashboard](/assets/images/RatRig/ratrig_Dashboard.png "Main Dashboard"){: style="width: 50%"}](/assets/images/RatRig/ratrig_Dashboard.png "Main Dashboard")

Here you will see a menu on the left will all the tabs neccesary to interact with the printer. Additionally, there will be a menu displaying recent errors as pictured.

2. There is also the option of seeing different statistics about the printer, this includes print time and filament usage.  
3. To print a file first head to the G-code Files tab, this will open a list of previous print as well as the option to upload a file of your choice (.gcode)  

[![G-code Files](/assets/images/RatRig/ratrig_Gcode_Files.png "G-code Files"){: style="width: 50%"}](/assets/images/RatRig/ratrig_Gcode_Files.png "G-code Files")

4. Once the file has been uploaded, it will show up at the top of the list. From this point you can select the file and click it, a menu should pop up with different options. 

[![G-code Option Menu](/assets/images/RatRig/ratrig_Files_Menu.png "G-code Option Menu"){: style="width: 50%"}](/assets/images/RatRig/ratrig_Files_Menu.png "G-code Option Menu")


5. If you think the file is ready to go click on the "print start" option. However, there's also the option of visualizing it beforehand.
