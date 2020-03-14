import numpy as np 
import csv
import pandas as pd 
import matplotlib.pyplot as plt











file = open("data2.txt","r")
xpoints = []
data = file.readlines()

for line in data:
	xpoints.append(line.split("\n")[0])
print(xpoints)
xpoints = np.array(xpoints).astype(np.int)
weights = np.ones_like(xpoints)/float(len(xpoints))
plt.hist(xpoints, color = 'blue',weights = weights)
plt.xlabel("Random Variable X")
plt.ylabel("Probability")
plt.show()