(defun sigs()
  (interactive)
  (sigs-create-signal "SourceTreeWindow.h")
  (sigs-create-signal "ModuleContainerWindow.h")
  (sigs-create-signal "ModuleWindow.h")
  (sigs-create-signal "MainDisplayWindow.h")
  (sigs-create-signal "TrackViewContainer.h"))

(defun sigs-create-signal(InHeaderName)
  (myqt-new-method-declaration-create InHeaderName
                                      "void" "SignalCompileSuccess"
                                      (list (list "QString" "InTrackName")
                                            (list "QString" "InASTPath")
                                            (list "QString" "InFileName")
                                            (list "QString" "InErrors")
                                            (list "QString" "InOutput"))
                                      "Public Signals"))

(defun new-slot()
  (interactive)
  (new-slot-create "SourceTreeWindow")
  (new-slot-create "ModuleContainerWindow")
  (new-slot-create "ModuleWindow")
  (new-slot-create "MainDisplayWindow")
  (new-slot-create "TrackViewContainer")
  (new-slot-create "TrackViewWindow"))

(defun new-slot-create(InClassName)
  (interactive)
  (myqt-new-method-create "Pass AST Compile Success Message"
                          "void"
                          "SlotCompileSuccess"
                          InClassName
                          (list (list "QString" "InTrackName")
                                (list "QString" "InASTPath")
                                (list "QString" "InFileName")
                                (list "QString" "InErrors")
                                (list "QString" "InOutput"))
                          "Public Slots"
                          nil))
   
   
