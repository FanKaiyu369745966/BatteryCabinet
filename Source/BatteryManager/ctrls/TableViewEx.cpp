#include "TableViewEx.h"

TableViewEx::TableViewEx(QWidget *parent) : QTableView(parent)
{
    init();
}

void TableViewEx::init()
{
    setStyleSheet("QTableView {border: 1px solid #22252A; background: #2D3035;}\
                  QTableView::item {font: 15pt Microsoft YaHei; color: #CCCCCC;\
                                    padding-left: 5px; padding-right: 5px; border: none; background: #2D3035;\
                                    border-right: 1px solid #DDDDDD; border-bottom: 1px solid #DDDDDD;}\
                  QTableView::item:selected {background: #DB6574; color:#FFFFFF}\
                  QTableView::item:selected:!active {color: #FFFFFF;}\
                  QHeaderView::section{background:#2D3035; color:#FFFFFF; height:40px; font:12pt Microsoft YaHei;}\
                  QHeaderView{background:#2D3035}");

    setSelectionBehavior(QAbstractItemView::SelectRows);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setSortingEnabled(false);
    verticalHeader()->hide();
    setWordWrap(false);
    setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    setShowGrid(false);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    horizontalHeader()->setHighlightSections(false);
    setAlternatingRowColors(true);
    setFrameShape(QFrame::NoFrame);
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void TableViewEx::setTableModel(QAbstractTableModel *model, bool isInteractive)
{
    this->setModel(model);
    if(isInteractive)
    {
        this->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    }
}
