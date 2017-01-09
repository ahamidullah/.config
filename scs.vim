"set background=dark
"hi clear
"if exists("syntax_on")
"    syntax reset
"endif
let g:colors_name="scs"

hi CursorLine    guibg=#0000cd guibg=#171717
"hi Normal       term=NONE cterm=NONE ctermfg=Gray ctermbg=18
hi Normal        guifg=#fffacd guibg=#171717
hi Statement     guifg=#fffacd guibg=#171717
"hi NonText      term=NONE cterm=NONE ctermfg=Gray  ctermbg=18

"hi Statement    term=NONE cterm=NONE ctermfg=White  ctermbg=18
"hi Statement    gui=NONE guifg=White guibg=18
"hi Special      term=NONE cterm=NONE ctermfg=White ctermbg=18
"hi Special      gui=NONE guifg=White guibg=18
"hi Constant     term=NONE cterm=NONE ctermfg=Cyan ctermbg=18
"hi Constant      guifg=#e9967a guibg=#171717
hi Constant       term=bold cterm=none ctermfg=7 gui=none guifg=LightGray
"hi Number        guifg=blue guibg=#171717
hi Comment       guifg=#a9a9a9 guibg=#171717
"hi Preproc      term=NONE cterm=NONE ctermfg=Cyan ctermbg=18
"hi Preproc      gui=NONE guifg=#99CCFF guibg=18
"hi Type         term=NONE cterm=NONE ctermfg=Gray ctermbg=18
"hi Type         gui=NONE guifg=#CCCCCC guibg=18
hi Identifier    guifg=#bc8f8f guibg=#171717
hi Function      guifg=#ff7f50 guibg=#171717
"hi cType   term=NONE cterm=NONE ctermfg=White ctermbg=18
"hi cTypeInst   term=NONE cterm=NONE ctermfg=White ctermbg=18
"hi cTypedefType   term=NONE cterm=NONE ctermfg=White ctermbg=18
"hi Identifier   term=NONE cterm=NONE ctermfg=Yellow ctermbg=18

"hi StatusLine   term=bold cterm=bold ctermfg=Black ctermbg=White
"hi StatusLine   gui=bold guifg=Black guibg=White

"hi StatusLineNC term=NONE cterm=NONE ctermfg=Black ctermbg=White
"hi StatusLineNC gui=NONE guifg=Black guibg=White

"hi Visual       term=NONE cterm=NONE ctermfg=Black ctermbg=250
"hi Visual       gui=NONE guifg=Black guibg=250

"hi Search       term=NONE cterm=NONE ctermbg=250
"hi Search       gui=NONE guibg=250

"hi VertSplit    term=NONE cterm=NONE ctermfg=Black ctermbg=White
"hi VertSplit    gui=NONE guifg=Black guibg=White

"hi Directory    term=NONE cterm=NONE ctermfg=Green ctermbg=18
"hi Directory    gui=NONE guifg=Green guibg=18

"hi WarningMsg   term=standout cterm=NONE ctermfg=Red ctermbg=18
"hi WarningMsg   gui=standout guifg=Red guibg=18

"hi Error        term=NONE cterm=NONE ctermfg=White ctermbg=Red
"hi Error        gui=NONE guifg=White guibg=Red

"hi Cursor       ctermfg=Black ctermbg=Black
"hi Cursor       guifg=Black guibg=Yellow

"hi MatchParen   cterm=NONE ctermbg=WHITE ctermfg=GRAY
