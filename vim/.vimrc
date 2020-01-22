:colorscheme koehler
set nocompatible
syntax on
set tabstop=4
set shiftwidth=4
set expandtab
set autoindent
set showmatch
set hlsearch
set ff=unix
set ffs=unix,dos
set guicursor=n-v-c:block,o:hor50,i-ci:ver15,r-cr:hor30,sm:block
set cindent
set wildmode=full
set wildmenu

nnoremap + :cnext<CR> :norm! zz<CR> :copen<CR>
nnoremap - :cprev<CR> :norm! zz<CR> :copen<CR>
