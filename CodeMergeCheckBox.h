/*****************************************************************************
 * FILE NAME    : CodeMergeCheckBox.h
 * DATE         : December 03 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _codemergecheckbox_h_
#define _codemergecheckbox_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define CODE_MERGE_CHECK_BOX_WIDTH      20
#define CODE_MERGE_CHECK_BOX_HEIGHT     20

/*****************************************************************************!
 * Exported Class : CodeMergeCheckBox
 *****************************************************************************/
class CodeMergeCheckBox : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  CodeMergeCheckBox             (QWidget *parent);

 //! Destructor
 public :
  ~CodeMergeCheckBox            ();

 //! Public Methods
 public :
  void                          SetChecked              (bool InChecked);
  bool                          GetChecked              (void);

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          initialize              ();
  void                          CreateSubWindows        ();
  void                          InitializeSubWindows    ();
  void                          resizeEvent             (QResizeEvent* InEvent);
  void                          mousePressed            (QMouseEvent* InEvent);
  void                          paintEvent              (QPaintEvent* InEvent);

 //! Private Data
 private :
  bool                          Checked;
  QColor                        StartingColor;
  QColor                        EndingColor;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :
  void                          SignalChecked           (void);
  void                          SignalUnChecked         (void);
  void                          SignalCheckStateChanged (bool InChecked);

 //! Public Actions
 public :

};

#endif /* _codemergecheckbox_h_*/
