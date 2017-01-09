" Vim color file
" Maintainer:   Maarten Slaets
" Last Change:  2002 Aug Gray

" Color settings similar to that used in IBM Edit

set background=dark
hi clear
if exists("syntax_on")
    syntax reset
endif
let g:colors_name="ibmedit"

hi Normal       term=NONE cterm=NONE ctermfg=Gray ctermbg=18
hi Normal       gui=NONE guifg=#CCCCCC guibg=18
hi NonText      term=NONE cterm=NONE ctermfg=Gray  ctermbg=18
hi NonText      gui=NONE guifg=#CCCCCC guibg=18

hi Statement    term=NONE cterm=NONE ctermfg=White  ctermbg=18
hi Statement    gui=NONE guifg=White guibg=18
hi Special      term=NONE cterm=NONE ctermfg=White ctermbg=18
hi Special      gui=NONE guifg=White guibg=18
hi Constant     term=NONE cterm=NONE ctermfg=Cyan ctermbg=18
hi Constant     gui=NONE guifg=#99CCFF guibg=18
hi Comment      term=NONE cterm=NONE ctermfg=Blue ctermbg=18
hi Comment      gui=NONE guifg=#6666FF guibg=18
hi Preproc      term=NONE cterm=NONE ctermfg=Cyan ctermbg=18
hi Preproc      gui=NONE guifg=#99CCFF guibg=18
hi Type         term=NONE cterm=NONE ctermfg=Gray ctermbg=18
hi Type         gui=NONE guifg=#CCCCCC guibg=18
hi Identifier   term=NONE cterm=NONE ctermfg=Gray ctermbg=18
hi Identifier   gui=NONE guifg=#CCCCCC guibg=18
hi cFuncName   term=NONE cterm=NONE ctermfg=Yellow ctermbg=18
hi cType   term=NONE cterm=NONE ctermfg=White ctermbg=18
hi cTypeInst   term=NONE cterm=NONE ctermfg=White ctermbg=18
hi cTypedefType   term=NONE cterm=NONE ctermfg=White ctermbg=18
"hi Identifier   term=NONE cterm=NONE ctermfg=Yellow ctermbg=18

hi StatusLine   term=bold cterm=bold ctermfg=Black ctermbg=White
hi StatusLine   gui=bold guifg=Black guibg=White

hi StatusLineNC term=NONE cterm=NONE ctermfg=Black ctermbg=White
hi StatusLineNC gui=NONE guifg=Black guibg=White

hi Visual       term=NONE cterm=NONE ctermfg=Black ctermbg=250
hi Visual       gui=NONE guifg=Black guibg=250

hi Search       term=NONE cterm=NONE ctermbg=250
hi Search       gui=NONE guibg=250

hi VertSplit    term=NONE cterm=NONE ctermfg=Black ctermbg=White
hi VertSplit    gui=NONE guifg=Black guibg=White

hi Directory    term=NONE cterm=NONE ctermfg=Green ctermbg=18
hi Directory    gui=NONE guifg=Green guibg=18

hi WarningMsg   term=standout cterm=NONE ctermfg=Red ctermbg=18
hi WarningMsg   gui=standout guifg=Red guibg=18

hi Error        term=NONE cterm=NONE ctermfg=White ctermbg=Red
hi Error        gui=NONE guifg=White guibg=Red

"hi Cursor       ctermfg=Black ctermbg=Black
"hi Cursor       guifg=Black guibg=Yellow

hi CursorLine   cterm=NONE ctermbg=90
hi MatchParen   cterm=NONE ctermbg=WHITE ctermfg=GRAY
