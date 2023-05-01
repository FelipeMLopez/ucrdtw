import ucrdtw
import numpy as np
import matplotlib.pyplot as plt

data = np.cumsum(np.random.uniform(-0.5, 0.5, 1000000))
query = np.cumsum(np.random.uniform(-0.5, 0.5, 100))
dnc = np.zeros(1000000, dtype=np.int32)
loc, dist = ucrdtw.ucrdtws(data, query, 0.05, True, dnc, 1) # with stride 1
loc, dist = ucrdtw.ucrdtw(data, query, 0.05, True, dnc) # without stride
query = np.concatenate((np.zeros(loc), query)) + (data[loc] - query[0])

plt.figure()
plt.plot(data)
plt.plot(query)
plt.show()
