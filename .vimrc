" local vimrc file
set tabstop=2
set softtabstop=2
set shiftwidth=2
set noexpandtab

" highlight the 110th column, to
" be sure how much space is left
set colorcolumn=80
highlight ColorColumn ctermbg=darkgray

" path
set path+=./include/

let g:ycm_global_ycm_extra_conf = ".ycm_extra_conf.py"

" color
colorscheme void 

set nu
