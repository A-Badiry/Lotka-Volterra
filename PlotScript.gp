# gnuplot script
set title 'Visualization of the hare and fox population'
set xlabel 'Time (in days)'
set ylabel 'population'
plot 'Hdata.dat' using 2:1 with lines, 'Fdata.dat' using 2:1 with lines
