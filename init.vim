set cin aw nu rnu cul ic scs sb spr udf nowrap
set ts=4 sw=4 tm=50 mouse=a shm+=sI
" set et " Optional: insert spaces instead of tabs.
ca Hash w !cpp -dD -P -fpreprocessed \| tr -d '[:space:]' \| md5sum \| cut -c-6
colorscheme lunaperche
