"*****************************************
"Name 	:	Archit Singh             *
"Email	:	architsingh456@gmail.com *
"GitHub :	archit-1997              *
"*****************************************

"----------------------------------------------
"Neovim Configuration File
"----------------------------------------------



"Basic configurations
set nu
set relativenumber
syntax on
colorscheme base16-solarized-dark
let g:NERDTreeWinPos = "right"
set foldmethod=indent
set clipboard=unnamed
set noswapfile
set incsearch
set softtabstop=4
set linebreak
set showbreak=+++
set autoindent
set copyindent
set numberwidth=5
set linespace=3
set splitright
set termguicolors
"set guifont=Consolas:h12
"set guifont=Cascadia\ Mono\ PL:h12
let g:auto_save = 1
"-----------------------------------------------

" Enable folding
set foldmethod=indent
set foldlevel=99
"Enable folding with the spacebar
nnoremap <space> za
"----------------------------------------------


"----------------------------------------------
"Competitive Programming 
"---------------------------------------------

"Compiling a .cpp program
autocmd filetype cpp nnoremap <f5> :w <bar> !g++ -std=c++11 -O2 -Wall % -o %:r && ./%:r <cr>

"----------------------------------------------


"----------------------------------------------
"System date and time settings
"----------------------------------------------
let g:airline_section_b = '%{strftime(" %d %b %Y %H:%M")}'
"----------------------------------------------


"----------------------------------------------
"For formatting the file
"----------------------------------------------
au BufNewFile,BufRead *.py,*.java,*.cpp,*.c,*.rkt,*.h
    \ set tabstop=4 |
    \ set softtabstop=4 |
    \ set shiftwidth=4 |
    \ set textwidth=120 |
    \ set expandtab |
    \ set autoindent |
    \ set fileformat=unix | 


set encoding=utf-8
"----------------------------------------------


"----------------------------------------------
"Airline settings
"----------------------------------------------
" enable tabline
let g:airline#extensions#tabline#enabled = 1

" enable powerline fonts
let g:airline_powerline_fonts = 1
let g:airline_theme = 'base16_vim'

" Always show tabs
set showtabline=10

set noshowmode
if !exists('g:airline_symbols')
    let g:airline_symbols = {}
endif
"----------------------------------------------
" airline symbols
"----------------------------------------------
 let g:airline_symbols.branch = ''
 let g:airline_symbols.readonly = '牢'
"----------------------------------------------

"----------------------------------------------
"leader for nvim"
"----------------------------------------------
let mapleader = " "
"----------------------------------------------


"----------------------------------------------
"leader keybindings
"----------------------------------------------

nmap <leader>so	:source $MYVIMRC<CR>
nmap <leader>s 	:w<CR>
nmap <leader>q	:wq<CR>
nmap <leader>fq	:qa!<CR>
nmap <leader>t 	:NERDTreeToggle<CR>
nmap <leader>d  :1,$d<CR>

"For opening files in the new tab and then type the file name
nmap <leader>o	:tabedit
"For going to the next tab
nmap <leader>j	:tabn<CR>
"For opening a new tab to the right
nmap <leader>n	:tabnew<CR>
"----------------------------------------------


"----------------------------------------------
"Full screen using ctrl+Enter
"----------------------------------------------

"----------------------------------------------
"Ale lint settings
"----------------------------------------------
let g:ale_lint_on_enter = 1
let g:ale_linters = {'cpp': ['clang']}
let g:ale_lint_on_text_changed = 'always'
let g:ale_lint_delay=200


"-----------------------------------------
"CtrlP fuzzy search plugin
"-----------------------------------------
let g:ctrlp_map='<c-p>'
let g:ctrlp_show_hidden=1
set wildignore+=.git
let g:ctrlp_working_path_mode = 'ra'

"-----------------------------------------


"----------------------------------------------
"vim plug plugin
"----------------------------------------------

call plug#begin(stdpath('data') . '/plugged')
Plug '907th/vim-auto-save'
Plug 'Shougo/vimproc.vim'
Plug 'preservim/nerdtree'
Plug 'tiagofumo/vim-nerdtree-syntax-highlight'
Plug 'sheerun/vim-polyglot'
Plug 'Raimondi/delimitMate'
Plug 'vim-airline/vim-airline'
Plug 'dense-analysis/ale'
Plug 'ryanoasis/vim-devicons'
Plug 'vim-airline/vim-airline-themes'
Plug 'rafi/awesome-vim-colorschemes'
Plug 'drewtempelmeyer/palenight.vim'
Plug 'ervandew/supertab'
Plug 'chriskempson/base16-vim'
Plug 'lambdalisue/vim-fullscreen'
Plug 'tibabit/vim-templates'
Plug 'tpope/vim-commentary'
Plug 'kien/ctrlp.vim'
call plug#end()
"---------------------------------------------

