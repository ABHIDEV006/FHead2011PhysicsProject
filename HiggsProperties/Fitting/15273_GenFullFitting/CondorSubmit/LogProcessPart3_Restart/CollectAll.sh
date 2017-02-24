mkdir -p Collected

for i1 in JobBothS JobBoth
do
   for i2 in 5plet SMVV
   do
      for i3 in A J
      do
         for i in Calculated/${i1}_${i2}_ggPDF_${i3}_*_*
         do
            i=`basename ${i/.out}`
            echo $i
            i4=`echo $i | cut --delim='_' --field=5`
            sed "s/^/${i4} /" < Calculated/$i.out
         done | grep -v "Job" | grep -v nan \
            | TextToTree Collected/${i1}_${i2}_${i3}.root 11 "L:ID:Pn:Pp:P:PPn:PPp:PP:PLn:PLp:PL"
      done
   done
done