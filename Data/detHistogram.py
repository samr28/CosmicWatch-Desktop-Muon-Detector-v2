import matplotlib.pyplot as plt
import numpy as np

dataFile = open("det2/CLEAN_DATA.txt")	# Open data file

words = dataFile.read().split()		# Split into an array (spaces)

dataPts = int(len(words)/6)         # Number of data points

time = []                           # Create array for timestamps
numDet = list(range(dataPts))                         # Create array for altitude data points


for i in range(dataPts):            # Loop through all of the data points
    time.append(float(words[i*6+1]))

print(time)

linex = plt.hist(time)	        # Plot time vs altitude

plt.xlabel('Time (s)')			    # Label the x axis
plt.ylabel('Num  Detected')		    # Label the y axis
plt.title('Num Detected vs Time')	    # Put a title on the grapg
plt.grid(True)				        # Add grid
plt.show()				            # Show the graph in a nice box
