/*****************************************************************************
 * FILE NAME    : ModuleToolBar.cpp
 * DATE         : December 02 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ModuleToolBar.h"

/*****************************************************************************!
 * Function : ModuleToolBar
 *****************************************************************************/
ModuleToolBar::ModuleToolBar
() : QFrame()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);

  setFrameShape(QFrame::Panel);
  setFrameShadow(QFrame::Sunken);
  setLineWidth(2);

  initialize();
}

/*****************************************************************************!
 * Function : ~ModuleToolBar
 *****************************************************************************/
ModuleToolBar::~ModuleToolBar
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ModuleToolBar::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  ActionDisplayModulesButtonPushed = new QAction("DisplayModulesButtonPushed", this);
  connect(ActionDisplayModulesButtonPushed, SIGNAL(triggered()), this, SLOT(SlotDisplayModulesButtonPushed()));
  ActionDisplaySourceFilesButtonPushed = new QAction("DisplaySourceFilesButtonPushed", this);
  connect(ActionDisplaySourceFilesButtonPushed, SIGNAL(triggered()), this, SLOT(SlotDisplaySourceFilesButtonPushed()));
  ActionDisplayTargetsButtonPushed = new QAction("DisplayTargetsButtonPushed", this);
  connect(ActionDisplayTargetsButtonPushed, SIGNAL(triggered()), this, SLOT(SlotDisplayTargetsButtonPushed()));
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ModuleToolBar::CreateSubWindows()
{
  //! Create the DisplayModulesButton button  
  DisplayModulesButton = new QPushButton();
  DisplayModulesButton->setParent(this);
  DisplayModulesButton->setText("M");
  DisplayModulesButton->move(0, 1);
  DisplayModulesButton->resize(24,24);
  connect(DisplayModulesButton, SIGNAL(pressed()), this, SLOT(SlotDisplayModulesButtonPushed()));

  //! Create the DisplaySourceFilesButton button
  DisplaySourceFilesButton = new QPushButton();
  DisplaySourceFilesButton->setParent(this);
  DisplaySourceFilesButton->setText("S");
  DisplaySourceFilesButton->move(25, 1);
  DisplaySourceFilesButton->resize(24,24);
  connect(DisplaySourceFilesButton, SIGNAL(pressed()), this, SLOT(SlotDisplaySourceFilesButtonPushed()));

  //! Create the DisplayTargetsButton button
  DisplayTargetsButton = new QPushButton();
  DisplayTargetsButton->setParent(this);
  DisplayTargetsButton->setText("T");
  DisplayTargetsButton->move(50, 1);
  DisplayTargetsButton->resize(24,24);
  connect(DisplayTargetsButton, SIGNAL(pressed()), this, SLOT(SlotDisplayTargetsButtonPushed()));

  track2CheckBox = new CodeMergeCheckBox(this);
  track2CheckBox->SetChecked(true);
  
  track3CheckBox = new CodeMergeCheckBox(this);
  track3CheckBox->SetChecked(false);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ModuleToolBar::InitializeSubWindows()
{
  track2CheckBox = NULL;
  track3CheckBox = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ModuleToolBar::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   horizontalGap;
  int                                   track3CheckBoxW;
  int                                   track3CheckBoxH;
  int                                   track3CheckBoxY;
  int                                   track3CheckBoxX;
  int                                   track2CheckBoxW;
  int                                   track2CheckBoxH;
  int                                   track2CheckBoxY;
  int                                   track2CheckBoxX;
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();

  horizontalGap = 5;
  
  track2CheckBoxW = height - 4;
  track2CheckBoxX = width - ((track2CheckBoxW + horizontalGap) * 2);
  track2CheckBoxY = 2;
  track2CheckBoxH = height - 4;
  track2CheckBox->move(track2CheckBoxX, track2CheckBoxY);
  track2CheckBox->resize(track2CheckBoxW, track2CheckBoxH);

  track3CheckBoxW = height - 4;
  track3CheckBoxX = width - (track3CheckBoxW + horizontalGap);
  track3CheckBoxY = 2;
  track3CheckBoxH = height - 4;
  track3CheckBox->move(track3CheckBoxX, track3CheckBoxY);
  track3CheckBox->resize(track3CheckBoxW, track3CheckBoxH);
}

/*****************************************************************************!
 * Function : SlotDisplayModulesButtonPushed
 *****************************************************************************/
void
ModuleToolBar::SlotDisplayModulesButtonPushed(void)
{
  emit SignalDisplayModules();
}

/*****************************************************************************!
 * Function : SlotDisplaySourceFilesButtonPushed
 *****************************************************************************/
void
ModuleToolBar::SlotDisplaySourceFilesButtonPushed(void)
{
  emit SignalDisplaySource();
}

/*****************************************************************************!
 * Function : SlotDisplayTargetsButtonPushed
 *****************************************************************************/
void
ModuleToolBar::SlotDisplayTargetsButtonPushed(void)
{
  emit SignalDisplayTargets();
}
