vim.cmd([[
set cin aw nu rnu cul ic scs sb spr udf nowrap
set ts=4 sw=4 mouse=a shm+=sI
set scl=yes
set et
set path+=**
]])

vim.cmd([[
cabbrev Hash w !cpp -dD -P -fpreprocessed \| tr -d '[:space:]' \| md5sum \| cut -c-6
]])

-- --------------------------------------------------------------------------------
vim.g.mapleader = " "
vim.pack.add({
    "https://github.com/neovim/nvim-lspconfig",
    { src = "https://github.com/nvim-treesitter/nvim-treesitter", version = "main" },
    { src = 'https://github.com/nvim-mini/mini.nvim', version = 'stable' },
})

vim.lsp.enable({
    "clangd",
    "jdtls",
    "ty",
})
vim.api.nvim_create_autocmd("LspAttach", {
    callback = function(event)
        vim.keymap.set("n", "gd", vim.lsp.buf.definition, {
            buffer = event.buf,
            desc = "Go to definition",
        })
    end,
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

vim.keymap.set("n", "<leader>ff", ":find ", { desc = "Find file" })
vim.keymap.set("n", "<leader>fw", ":grep ", { desc = "Grep" })
