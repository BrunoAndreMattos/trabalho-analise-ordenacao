import matplotlib.pyplot as plt
from math import log, exp, factorial, sqrt

########################################
#### Plot a partir de dados gerados ####
########################################

fig = plt.figure()

ax = fig.add_subplot(111)
ax.set_title("Crescimento de funcoes")    
ax.set_xlabel('n')
ax.set_ylabel('f(n)')

x = range(2,200)
ax.plot(x,[100*n for n in x],label="100n")
ax.plot(x,[n**2 for n in x],label="n^2")

ax.legend(loc='upper left')
#ax.set_yscale("log", nonposx='clip') # coloca o eixo y em escala logaritmica

fig.savefig('graph.png')

plt.show()

