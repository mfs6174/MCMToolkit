a=[21 37 14 0 0 0 0 0 0 0 0 0 0 0
16 53 13 0 0 0 0 0 0 0 0 0 0 0
0 0 1 0 3 10 12 8 2 1 2 0 0 0
0 0 0 3 2 7 16 11 18 15 11 9 5 4
0 2 12 10 9 11 5 3 3 0 0 0 0 0];
clf;
hold on;
plot(a(1,:),'*-');
plot(a(2,:),'.--');
plot(a(3,:),'.-');
plot(a(4,:),'.-.');
plot(a(5,:),'o-');
legend('白内障','白内障（双眼）','青光眼','视网膜疾病','外伤');
axis([0,14,0,60]);
set(gca,'XTick',1:14,'XTickLabel',sprintf('%d|',2:15));
saveas(gcf,'fenbu','eps');

