vim.opt.cindent = true
vim.opt.autowrite = true
vim.opt.number = true
vim.opt.relativenumber = true
vim.opt.cursorline = true
vim.opt.ignorecase = true
vim.opt.smartcase = true
vim.opt.splitbelow = true
vim.opt.splitright = true
vim.opt.undofile = true
vim.opt.wrap = false
vim.opt.tabstop = 4
vim.opt.shiftwidth = 4
vim.opt.timeoutlen = 50
vim.opt.mouse = "a"
vim.opt.shortmess:append("sI")
vim.opt.expandtab = true

vim.cmd([[cabbrev Hash w !cpp -dD -P -fpreprocessed \| tr -d '[:space:]' \| md5sum \| cut -c-6]])

vim.cmd.colorscheme("vim")
-- vim.opt.background = "dark"
-- vim.api.nvim_set_hl(0, "CursorLine", { bg = "#11111b" })
-- vim.opt.background = "light"
-- vim.api.nvim_set_hl(0, "CursorLine", { bg = "#eff1f5" })

-- --------------------------------------------------------------------------------
-- The config above is for competitions. The config below is bespoke to my machine.
-- Uncomment one of the theme blocks and CursorLine highlights for competitions.
local themer_mode_file = vim.fn.expand("~/.config/themer/mode")
if vim.fn.filereadable(themer_mode_file) == 1 then
    local themer_mode = vim.trim(vim.fn.readfile(themer_mode_file, "", 1)[1] or "")
    if themer_mode == "dark" then
        vim.opt.background = "dark"
        vim.api.nvim_set_hl(0, "CursorLine", { bg = "#11111b" })
    elseif themer_mode == "light" then
        vim.opt.background = "light"
        vim.api.nvim_set_hl(0, "CursorLine", { bg = "#eff1f5" })
    end
end
-- --------------------------------------------------------------------------------
