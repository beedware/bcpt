vim.cmd([[
set cin aw nu rnu cul ic scs sb spr udf nowrap
set ts=4 sw=4 tm=50 mouse=a shm+=sI
set et
]])

vim.cmd([[
cabbrev Hash w !cpp -dD -P -fpreprocessed \| tr -d '[:space:]' \| md5sum \| cut -c-6
]])

vim.cmd([[
colorscheme vim
set bg=dark
highlight CursorLine guibg=#11111b gui=NONE
]])
-- vim.cmd([[
-- colorscheme vim
-- set bg=light
-- highlight CursorLine guibg=#eff1f5 gui=NONE
-- ]])

-- --------------------------------------------------------------------------------
-- The config above is for competitions. The config below is bespoke to my machine.
-- Uncomment one of the theme blocks and CursorLine highlights for competitions.
local themer_mode_file = vim.fn.expand("~/.config/themer/mode")
if vim.fn.filereadable(themer_mode_file) == 1 then
    local themer_mode = vim.trim(vim.fn.readfile(themer_mode_file, "", 1)[1] or "")
    if themer_mode == "dark" then
        vim.cmd("set bg=dark")
        vim.api.nvim_set_hl(0, "CursorLine", { bg = "#11111b" })
    elseif themer_mode == "light" then
        vim.cmd("set bg=light")
        vim.api.nvim_set_hl(0, "CursorLine", { bg = "#eff1f5" })
    end
end
-- --------------------------------------------------------------------------------
