set incsearch "show the pattern as you type
set nohlsearch
set ignorecase
set smartcase
set wildmenu
set laststatus=2

set splitright
set splitbelow
set mouse=a
vnoremap <space> <nop>
nnoremap <space> <nop>
let mapleader = " "
set autoindent 
set wrap
set textwidth=0
set wrapmargin=0

nnoremap  j gj
nnoremap  k gk

nnoremap  <C-k> {
xnoremap  <C-k> {
onoremap  <C-k> {

nnoremap  <C-j> }
xnoremap  <C-j> }
onoremap  <C-j> }

nnoremap  <C-h> ^
xnoremap  <C-h> ^
onoremap  <C-h> ^

nnoremap  <C-l> $
xnoremap  <C-l> $
onoremap  <C-l> $

"nnoremap H <C-w>h
"nnoremap J <C-w>j
"nnoremap K <C-w>k
"nnoremap L <C-w>l

map <C-s> :b %<.cpp<CR>
map <C-a> :b %<.h<CR>
nnoremap <f9> :silent make!\|redraw!\|cw<CR>
nnoremap <C-n> :cn<cr>:cope<cr>zt<C-w>p
nnoremap <C-p> :cp<cr>:cope<cr>zt<C-w>p
nnoremap <C-c> :ccl<cr>
nnoremap <C-q> :copen<cr>

command! -nargs=+ G execute 'silent grep! <args>' | copen

nnoremap gb :ls<cr>:b<space>
nnoremap gp :b#<cr>
nnoremap <leader>h :set hlsearch!<cr>
" paste last yank
nnoremap <leader>p "0p
nnoremap <leader>P "0P

syntax off
highlight Normal     guifg=black guibg=#ffffd7
highlight Comment    guifg=blue
highlight Error      gui=NONE guibg=NONE guifg=NONE
highlight Todo      gui=NONE guibg=NONE
highlight Constant   gui=NONE guifg=NONE
highlight Identifier gui=NONE guifg=NONE
highlight Statement  gui=NONE guifg=NONE
highlight PreProc    gui=NONE guifg=NONE
highlight Type       gui=NONE guifg=NONE
highlight Special    gui=NONE guifg=NONE
highlight Underlined gui=NONE guifg=NONE
highlight Function gui=NONE guifg=NONE
highlight Delimiter gui=NONE guifg=NONE

if has('gui_running')
	set ghr=0
	set guifont=Fixed\ Medium\ Semi-Condensed\ 10
endif

function! ToggleGUI()
  if &guioptions=='i'
    exec('set guioptions=imTrL')
  else
    exec('set guioptions=i')
  endif
endfunction

map <F11> <Esc>:call ToggleGUI()<cr>

" by default, hide gui menus
set guioptions=i
