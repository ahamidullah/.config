set background=dark
hi clear
if exists("syntax_on")
    syntax reset
endif
let g:colors_name="neon"

hi Normal       term=NONE cterm=NONE ctermfg=white ctermbg=black
hi NonText      term=NONE cterm=NONE ctermfg=white  ctermbg=black

hi Statement    term=NONE cterm=NONE ctermfg=DarkMagenta  ctermbg=black 
hi Special      term=NONE cterm=NONE ctermfg=White ctermbg=black
hi Constant     term=NONE cterm=NONE ctermfg=DarkCyan ctermbg=black
hi Comment      term=NONE cterm=NONE ctermfg=DarkBlue ctermbg=black
hi Preproc      term=NONE cterm=NONE ctermfg=Cyan ctermbg=black
hi Type         term=NONE cterm=NONE ctermfg=blue ctermbg=black
hi Identifier   term=NONE cterm=NONE ctermfg=DarkRed ctermbg=black

hi StatusLine   term=bold cterm=bold ctermfg=Magenta ctermbg=Black

hi StatusLineNC term=NONE cterm=NONE ctermfg=Magenta ctermbg=Black

hi Visual       term=NONE cterm=NONE ctermbg=white

hi Search       term=NONE cterm=NONE ctermbg=Black

hi VertSplit    term=NONE cterm=NONE ctermfg=Magenta ctermbg=Black

hi Directory    term=NONE cterm=NONE ctermfg=Green ctermbg=Black

hi WarningMsg   term=standout cterm=NONE ctermfg=Red ctermbg=Black

hi Error        term=NONE cterm=NONE ctermfg=White ctermbg=Red

hi CursorLine   cterm=NONE ctermbg=90

hi MatchParen   cterm=NONE ctermbg=Yellow ctermfg=Black
