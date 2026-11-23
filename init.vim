set cin aw nu rnu cul ic scs sb spr udf nowrap
set ts=4 sw=4 tm=50 mouse=a shm+=sI
set et

ca Hash w !cpp -dD -P -fpreprocessed \| tr -d '[:space:]' \| md5sum \| cut -c-6

colorscheme vim
" set bg=dark
" highlight CursorLine guibg=#11111b gui=NONE
" set bg=light
" highlight CursorLine guibg=#eff1f5 gui=NONE

" --------------------------------------------------------------------------------
" The config above is for competitions. The config below is bespoke to my machine.
" Uncomment one of the theme block and CursorLine highlight for competitons.
let s:themer_mode_file = expand('~/.config/themer/mode')
if filereadable(s:themer_mode_file)
    let s:themer_mode = trim(get(readfile(s:themer_mode_file, '', 1), 0, ''))
    if s:themer_mode ==# 'dark'
        set bg=dark
        highlight CursorLine guibg=#11111b gui=NONE
    elseif s:themer_mode ==# 'light'
        set bg=light
        highlight CursorLine guibg=#eff1f5 gui=NONE
    endif
endif
" --------------------------------------------------------------------------------
