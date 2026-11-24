vim.g.mapleader = " "

vim.cmd([[
set cin aw nu rnu cul ic scs sb spr udf nowrap
set ts=4 sw=4 tm=50 mouse=a shm+=sI
set scl=yes
set et
]])

vim.cmd([[
cabbrev Hash w !cpp -dD -P -fpreprocessed \| tr -d '[:space:]' \| md5sum \| cut -c-6
]])

vim.cmd([[
colorscheme lunaperche
]])

-- --------------------------------------------------------------------------------
vim.pack.add({
    "https://github.com/neovim/nvim-lspconfig",
    { src = "https://github.com/nvim-treesitter/nvim-treesitter", version = "main" },
})

vim.lsp.enable({
    "clangd",
    "jdtls",
    "pyright",
})

require("nvim-treesitter").install({
    "c", "cpp", "java", "python", "lua", "nix",
})
vim.api.nvim_create_autocmd("FileType", {
    pattern = { "c", "cpp", "java", "python", "lua", "nix" },
    callback = function()
        vim.treesitter.start()
    end,
})
-- --------------------------------------------------------------------------------
