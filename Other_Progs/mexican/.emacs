(set-language-environment "UTF-8")

(setq custom-file "~/.emacs-custom.el")
(load custom-file)

;; numero de colone
(column-number-mode t)

;; auto-indent
(add-hook 'c-mode-common-hook '(lambda () (c-toggle-auto-state 1)))

;; indentation style
(setq c-default-style "linux")

;; indent offset
(setq-default c-basic-offset 4)

;; Raccourcis
(global-set-key (kbd "C-c h") 'replace-string)
(global-set-key (kbd "C-c j") 'replace-regexp)
(global-set-key (kbd "C-c o") 'bury-buffer)
(global-set-key (kbd "C-c k") 'kill-this-buffer)

;; highlight
(show-trailing-whitespace t)

;; stop deleting empty line with the command 'delete-trailing-whitespace'
(delete-trailing-lines nil)

;; highligh successive whitespace
(global-hi-lock-mode 1) (add-hook 'change-major-mode-hook '(lambda () (highlight-regexp "\\(^\\s-*$\\)\n" 'hi-yellow)))

(global-hi-lock-mode 1)