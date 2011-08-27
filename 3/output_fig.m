function output_fig(xx,y_static,y_best_fit,name)
%y_static是原来的统计数据，y_best_fit是选出的拟合度最高的那个函数得到的数据，name是输出文件名。
    clf;
    hold on;
    %plot(y_static,'.-');
    p=plot(y_best_fit,xx,y_static,'.--');
    set(gca,'XTickLabel',sprintf('%d|',2000:2010))
    set(p,'MarkerSize',25);
    saveas(p,name,'eps')
end
