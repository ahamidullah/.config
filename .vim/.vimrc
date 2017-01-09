"fix vim's awful indents
set cindent 
set cinoptions=p0,n-1s,t0,{0,:1s,g1s,t0,(0,=.5s

if !exists("autocmd_colorscheme_loaded")
  let autocmd_colorscheme_loaded = 1
    autocmd ColorScheme * highlight Note      ctermbg=Green ctermfg=Black
      autocmd ColorScheme * highlight Fixme   ctermbg=Magenta ctermfg=Black
        autocmd ColorScheme * highlight Bug   ctermbg=Red ctermfg=Black
        endif

set nowrap
"set tabstop=8
"set softtabstop=8
"set shiftwidth=8
"set expandtab
set t_Co=256
set number
set cursorline
set incsearch
set hlsearch
set ignorecase
set lazyredraw          " redraw only when we need to.
set wildmenu
syntax on
color ibmedit

let mapleader=" "
imap jk <Esc>
nnoremap <Leader>w 0
nnoremap <Leader>t /TODO<CR>\|zz
nnoremap <Leader>e $
nnoremap <Leader>b ^
nnoremap <Leader>o :o 
nnoremap <Leader>s :w<CR> 
nnoremap <Leader>0 :qall<CR>
nnoremap <Leader>f m`o<Esc>``
nnoremap <Leader>g m`O<Esc>``
nnoremap <Leader>l <C-W>l
nnoremap <Leader>h <C-W>h
nnoremap <Leader>j <C-W>j
nnoremap <Leader>k <C-W>k
nnoremap <Leader>q :mks!<CR>
nnoremap <C-k> {
nnoremap <C-j> }
nnoremap ; :
nnoremap , `
nnoremap <Leader>h :noh<return><esc>

"set build and quickfix
set makeprg=clang\ /home/steve/dev/behaviorc/src/test.c\ -o\ test
nnoremap <F9> :cd ../build/c\|silent make\|redraw!\|cw\|cd ../../src<CR>
nnoremap <F10> :! /home/steve/dev/behaviorc/runtest.sh<CR>
noremap <F2> :cp<CR>
noremap <F1> :cn<CR>
noremap <F3> :cl<CR>

"hi cCustomFunc  gui=NONE guifg=white
"hi cCustomClass gui=NONE guifg=white

if has("autocmd")
  " Highlight TODO, FIXME, NOTE, etc.
            if v:version > 701
                autocmd Syntax * call matchadd('Todo',  '\W\zs\(TODO\|CHANGED\|XXX\)')
                            autocmd Syntax * call matchadd('Note', '\W\zs\(NOTE\|INFO\|IDEA\)')
                            autocmd Syntax * call matchadd('Fixme', '\W\zs\(FIXME\)')
                            autocmd Syntax * call matchadd('Bug', '\W\zs\(BUG\|HACK\)')
                              endif
                              endif

