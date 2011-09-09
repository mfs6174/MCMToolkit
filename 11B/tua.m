figure
hold on
for k=1:length(xa)
    text(xa(k),ya(k),{k});
end

for i=1:length(pa)
    plot([xa(pa(i,1)) xa(pa(i,2))],[ya(pa(i,1)) ya(pa(i,2))]);
end

for i=1:length(pinga)
    plot(xa(pinga(i)),ya(pinga(i)),'r*')
end

for i=1:length(chua)
    plot(xa(chua(i)),ya(chua(i)),'ko')
end