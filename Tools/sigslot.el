(defun NewSignal()
  (interactive)
  (sigs-create-signal "TrackViewContainer.h")
  (sigs-create-signal "TrackViewWindow.h"))

(defun sigs-create-signal(InHeaderName)
  (myqt-new-method-declaration-create InHeaderName
                                      "void" "SignalTreeClear"
                                      nil
                                      "Public Signals"))

(defun NewSlot()
  (interactive)
  (new-slot-create "ASTDisplayWindow")
  (new-slot-create "TrackViewWindow"))

(defun new-slot-create(InClassName)
  (interactive)
  (myqt-new-method-create "Send 'Clear Source Tree Window' message "
                          "void"
                          "SlotTreeClear"
                          InClassName
                          nil
                          "Public Slots"
                          nil))
   
   
