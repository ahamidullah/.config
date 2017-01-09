set background=light
hi clear
if exists("syntax_on")
    syntax reset
endif
let g:colors_name="new"

hi Normal       term=NONE cterm=NONE ctermfg=Black ctermbg=230
hi Normal       gui=NONE guifg=#CCCCCC guibg=230
hi NonText      term=NONE cterm=NONE ctermfg=Black  ctermbg=230
hi NonText      gui=NONE guifg=#CCCCCC guibg=230

hi Statement    term=NONE cterm=NONE ctermfg=Black  ctermbg=230
hi Statement    gui=NONE guifg=Black guibg=230
hi Special      term=NONE cterm=NONE ctermfg=Black ctermbg=230
hi Special      gui=NONE guifg=Black guibg=230
hi Constant     term=NONE cterm=NONE ctermfg=Black ctermbg=230
hi Constant     gui=NONE guifg=#99CCFF guibg=230
hi Comment      term=NONE cterm=NONE ctermfg=Black ctermbg=230
hi Comment      gui=NONE guifg=#6666FF guibg=230
hi Preproc      term=NONE cterm=NONE ctermfg=Black ctermbg=230
hi Preproc      gui=NONE guifg=#99CCFF guibg=230
hi Type         term=NONE cterm=NONE ctermfg=Black ctermbg=230
hi Type         gui=NONE guifg=#CCCCCC guibg=230
hi Identifier   term=NONE cterm=NONE ctermfg=Black ctermbg=230
hi Identifier   gui=NONE guifg=#CCCCCC guibg=230
hi cFuncName   term=NONE cterm=NONE ctermfg=Black ctermbg=230
hi cType   term=NONE cterm=NONE ctermfg=Black ctermbg=230
hi cTypeInst   term=NONE cterm=NONE ctermfg=Black ctermbg=230
hi cTypedefType   term=NONE cterm=NONE ctermfg=Black ctermbg=230
"hi Identifier   term=NONE cterm=NONE ctermfg=Yellow ctermbg=230

hi StatusLine   term=bold cterm=bold ctermfg=230 ctermbg=Black
hi StatusLine   gui=bold guifg=Black guibg=White

hi StatusLineNC term=NONE cterm=NONE ctermfg=230 ctermbg=Black
hi StatusLineNC gui=NONE guifg=Black guibg=White

hi Visual       term=NONE cterm=NONE ctermfg=230 ctermbg=Black
hi Visual       gui=NONE guifg=Black guibg=250

hi Search       cterm=NONE ctermfg=124 ctermbg=NONE
hi Search       gui=NONE guibg=250

hi VertSplit    term=NONE cterm=NONE ctermfg=Black ctermbg=Black
hi VertSplit    gui=NONE guifg=Black guibg=White

hi Directory    term=NONE cterm=NONE ctermfg=Black ctermbg=230
hi Directory    gui=NONE guifg=Green guibg=230

hi WarningMsg   term=standout cterm=NONE ctermfg=Red ctermbg=230
hi WarningMsg   gui=standout guifg=Red guibg=230

hi Error        term=NONE cterm=NONE ctermfg=Red ctermbg=Red
hi Error        gui=NONE guifg=White guibg=Red

"hi Cursor       ctermfg=Black ctermbg=Black
"hi Cursor       guifg=Black guibg=Yellow

hi CursorLine   cterm=NONE ctermbg=215
hi MatchParen   cterm=NONE ctermbg=230 ctermfg=Black
hi ModeMsg   cterm=NONE ctermbg=Black ctermfg=230
hi MoreMsg   cterm=NONE ctermbg=230 ctermfg=Black
hi TabLine   cterm=NONE ctermbg=black ctermfg=230
hi TabLineSel   cterm=NONE ctermbg=black ctermfg=230
hi WildMenu   cterm=Reverse
