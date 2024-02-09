#Plot title
set title "Visualization of Lotka-Volterra model"


#Axes labels
set xlabel 'Time(days)'
set ylabel 'Population'


plot 'Hdata.dat' with lines title 'Hare Population',\
     'Fdata.dat' with lines title 'Fox Population'

