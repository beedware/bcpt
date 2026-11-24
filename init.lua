vim.cmd [[
set cin aw nu rnu cul ic scs sb spr udf nowrap
set ts=4 sw=4 mouse=a shm+=sI
set scl=yes
set et
set path+=**
]]
vim.cmd [[tnoremap <Esc> <C-\><C-n>]]

vim.cmd [[
cabbrev Hash w !cpp -dD -P -fpreprocessed \| tr -d '[:space:]' \| md5sum \| cut -c-6
]]
--------------------------------------------------------------------------------------------------------------------
vim.g.mapleader = " "
vim.g.netrw_banner = 0
vim.opt.guicursor:append "t:block-blinkon0"

vim.pack.add {
    "https://github.com/neovim/nvim-lspconfig",
    "https://github.com/nvim-treesitter/nvim-treesitter",
    "https://github.com/NeogitOrg/neogit",
}

vim.lsp.enable {
    "clangd",
    "jdtls",
    "ty",
}
vim.api.nvim_create_autocmd("LspAttach", {
    callback = function(event)
        vim.keymap.set("n", "gd", vim.lsp.buf.definition, {
            buffer = event.buf,
            desc = "Go to definition",
        })
    end,
})

require("nvim-treesitter").install {
    "c", "cpp", "java", "python", "lua", "nix",
}
vim.api.nvim_create_autocmd("FileType", {
    pattern = { "c", "cpp", "java", "python", "lua", "nix" },
    callback = function()
        vim.treesitter.start()
    end,
})

vim.keymap.set("n", "<leader>ff", ":find ", { desc = "Find file" })
vim.keymap.set("n", "<leader>fw", ":grep ", { desc = "Grep" })
vim.keymap.set("n", "-", ":Ex<CR>", { desc = "File Explorer" })
vim.keymap.set("n", "<leader>gg", ":Neogit<CR>", { desc = "Show neogit" })
local function open_terminal(split)
    local file = vim.api.nvim_buf_get_name(0)
    local cwd = vim.bo.buftype == "" and file ~= "" and vim.fs.dirname(file) or vim.fn.getcwd()
    vim.cmd(split)
    vim.fn.jobstart(vim.o.shell, { term = true, cwd = cwd })
    vim.cmd.startinsert()
end

vim.keymap.set("n", "<leader>tv", function()
    open_terminal("vnew")
end, { desc = "Vertical terminal" })
vim.keymap.set("n", "<leader>ts", function()
    open_terminal("new")
end, { desc = "Horizontal terminal" })

vim.api.nvim_create_autocmd("TextYankPost", {
  group = vim.api.nvim_create_augroup("HighlightYank", { clear = true }),
  callback = function()
    vim.hl.on_yank { higroup = "IncSearch", timeout = 200 }
  end,
})
