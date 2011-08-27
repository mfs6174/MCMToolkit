function output_fig(xx,y_static,y_best_fit,name,ss)
%y_static是原来的统计数据，y_best_fit是选出的拟合度最高的那个函数得到的数据，name是输出文件名。
    clf;
    hold on;
    p=plot(y_static,'.-');
    plot(y_best_fit,'--');
    set(gca,'XTick',[1:1:size(xx,2)])    
    set(gca,'XTickLabel',sprintf('%d|',ss:2010))
    set(p,'MarkerSize',25);
    legend(gca,'off');
    saveas(gcf,name,'eps')
end
