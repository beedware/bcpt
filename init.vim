set cin aw nu rnu cul ic scs sb spr udf nowrap
set ts=4 sw=4 tm=50 mouse=a shm+=sI
set et

ca Hash w !cpp -dD -P -fpreprocessed \| tr -d '[:space:]' \| md5sum \| cut -c-6

colorscheme vim
set bg=dark
highlight CursorLine guibg=#252525 gui=NONE
" set bg=light
" highlight CursorLine guibg=#eeeeee gui=NONE
