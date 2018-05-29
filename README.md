Middleton High School RFS 2018 Data
====================================
On May 11, 2018 the Middleton High School Rocket Team launched a class 2 rocket through the Rockets for Schools program. Our rocket carried a payload consisting of three main systems. One altitude (pressure based) recording device along with two muon detectors.

Altitude recording device
--------------
The altitude recording device consisted of an arduino nano connected to a BMP280 pressure sensor and a microsd card reader/writer. The BMP280 was connected via i2c while the microsd card was connected via SPI. This device was running the code located in [`Arduino/Altitude/`](https://github.com/samr28/MHS-RFS-2018/tree/master/Arduino/Altitude). It collected pressure (which was used to calculate the altitude) as well as the temperature.

The data follows the format shown below:
```
TIME(ms) t: TEMP p: PRESSURE(pa) a: ALTITUDE

ex:
1118 t: 16.30 p: 100233.52 a: 159.49
```
You can view the data in [`Data/alt1/`](https://github.com/samr28/MHS-RFS-2018/blob/master/Data/alt1).


Muon detectors
--------------
For information on the muon detectors that we built, please see the [CosmicWatch V2 repo](https://github.com/spenceraxani/CosmicWatch-Desktop-Muon-Detector-v2).

Unfortunately, one of our detectors (det1) did not record data during the flight so we only have data from det2.

You can view the data that we collected in [`Data/det1/`](https://github.com/samr28/MHS-RFS-2018/tree/master/Data/det1) and [`Data/det2/`](https://github.com/samr28/MHS-RFS-2018/tree/master/Data/det2).

Names of data files
--------------
`CLEAN_DATA.txt` - flight data

`DATA.txt` - raw data

`test.txt` - test data

Graphing
--------------
We used [Matplotlib](https://matplotlib.org/) to create different graphs. To view/modify them, see the python scripts in [`Data/`](https://github.com/samr28/MHS-RFS-2018/tree/master/Data)

Launch details
--------------
Important timestamps (ms):

`4475580` - liftoff

`4488218` - apogee

`4586298` - splashdown/landing

`4586298` - pressure data goes bad (likely due to the water)

Total flight time of about 110.7 seconds (1:50).
