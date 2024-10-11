import numpy as np

data = np.genfromtxt('temperature.csv', delimiter=',', skip_header=1)

days = data[:, 0]
temperatures = data[:, 1]

print("Days:", days)
print("Temperatures:", temperatures)


Mean_Temperature=np.mean(temperatures)
Median_Temperature=np.median(temperatures)
Varience_Temperature=np.var(temperatures)
Standard_Deviation_Temperature=np.std(temperatures)

print(f"Mean of Temperature: {Mean_Temperature}")
print(f"Median of Temperature: {Median_Temperature}")
print(f"Varience of Temperature: {Varience_Temperature}")
print(f"Standard Deviation of Temperature: {Standard_Deviation_Temperature}")