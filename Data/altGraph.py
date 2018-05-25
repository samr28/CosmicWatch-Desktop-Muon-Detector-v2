import matplotlib.pyplot as plt
import numpy as np

dataFile = open("alt1/DATA.txt")	# Open data file
words = dataFile.read().split()		# Split into an array (spaces)

dataPts = int(len(words)/7)         # Number of data points


time = []                           # Create array for timestamps
alt =[]                             # Create array for altitude data points

for i in range(dataPts):            # Loop through all of the data points
    time.append(float(words[i*7])/1000)
    alt.append(float(words[(i*7)+6]))

linex = plt.plot(time, alt)	        # Plot time vs altitude

plt.xlabel('Time (s)')			    # Label the x axis
plt.ylabel('Altitude (m)')		    # Label the y axis
plt.title('Altitude vs Time')	    # Put a title on the grapg
plt.grid(True)				        # Add grid
plt.show()				            # Show the graph in a nice box
