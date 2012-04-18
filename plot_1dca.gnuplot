set pm3d map
#set size square
#set logscale cb
unset key
unset colorbox
set palette gray
set ylabel "Iterations (i)"
set xlabel "Position (p)"
set yrange [0:`echo "$(echo $(wc -l < $filename) + 0 | bc -l)"`]
set yrange [`echo "$(echo $(wc -l < $filename) + 0 | bc -l)"`:0]
set xrange [0:`echo "$(echo $(head -n 1 $filename | wc -w) + 0 | bc -l)"`]
set xtics 1,`echo $repeatscore_xtics`
set ytics 0,`echo $repeatscore_ytics`
set terminal postscript eps color
set output "`echo $filename`.eps"
plot "`echo $filename`" matrix using ($1):($2):(1-$3) notitle with image
