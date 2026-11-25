vim.cmd([[
set cin aw nu rnu cul ic scs sb spr udf nowrap et
set ts=4 sw=4 mouse=a shm+=sI fcs=eob:\  scl=yes path+=**
]])

vim.cmd([[tnoremap <Esc> <C-\><C-n>]])

vim.cmd([[ cabbrev Hash w !cpp -dD -P -fpreprocessed \| tr -d '[:space:]' \| md5sum \| cut -c-6 ]])
--------------------------------------------------------------------------------------------------------------------
vim.g.mapleader = " "
vim.g.netrw_banner = 0
vim.opt.guicursor:append("t:block-blinkon0")

vim.pack.add({
  "https://github.com/neovim/nvim-lspconfig",
  "https://github.com/nvim-treesitter/nvim-treesitter",
  "https://github.com/NeogitOrg/neogit",
  "https://github.com/mfussenegger/nvim-dap",
  "https://github.com/mfussenegger/nvim-dap-python",
  "https://github.com/mfussenegger/nvim-jdtls",
  "https://github.com/miikanissi/modus-themes.nvim",
  { src = "https://github.com/igorlfs/nvim-dap-view", version = vim.version.range("1.*") },
})

require("modus-themes").setup({ styles = { comments = { italic = false }, keywords = { italic = false } } })

vim.cmd.colorscheme("modus")

local java_debug_jar = vim.env.JAVA_DEBUG_JAR
vim.lsp.config("jdtls", {
  init_options = {
    bundles = java_debug_jar and { vim.fn.expand(java_debug_jar) } or {},
  },
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
    local client = vim.lsp.get_client_by_id(event.data.client_id)
    if client and client.name == "jdtls" and java_debug_jar then
      require("jdtls").setup_dap({ hotcodereplace = "auto" })
    end
  end,
})

local dap = require("dap")
local dapview = require("dap-view")

dapview.setup({
  winbar = {
    default_section = "scopes",
    controls = { enabled = true },
  },
  windows = { terminal = { size = 0.40, position = "right" } },
  auto_toggle = true,
})

dap.adapters.codelldb = {
  type = "server",
  port = "${port}",
  executable = {
    command = vim.env.CODELLDB or "codelldb",
    args = { "--port", "${port}" },
  },
}
for _, language in ipairs({ "c", "cpp" }) do
  dap.configurations[language] = {
    {
      name = "Launch executable",
      type = "codelldb",
      request = "launch",
      program = function()
        local path = vim.fn.input("Executable: ", vim.fn.getcwd() .. "/", "file")
        return path ~= "" and vim.fn.fnamemodify(path, ":p") or dap.ABORT
      end,
      cwd = "${workspaceFolder}",
      stopOnEntry = false,
      terminal = "integrated",
    },
  }
end

require("dap-python").setup(vim.env.DEBUGPY_PYTHON or "python3")

vim.keymap.set("n", "<Right>", dap.step_into, { desc = "Debug: step into" })
vim.keymap.set("n", "<Down>", dap.step_over, { desc = "Debug: step over" })
vim.keymap.set("n", "<Left>", dap.step_out, { desc = "Debug: step out" })
vim.keymap.set("n", "<Up>", dap.restart_frame, { desc = "Debug: restart frame" })
vim.keymap.set("n", "<leader>db", dap.toggle_breakpoint, { desc = "Debug: toggle breakpoint" })
vim.keymap.set("n", "<leader>dr", dap.continue, { desc = "Debug: run or continue" })
vim.keymap.set("n", "<leader>dt", dap.terminate, { desc = "Debug: terminate session" })
vim.keymap.set("n", "<leader>dw", dapview.add_expr, { desc = "Debug: add watch expression" })
vim.keymap.set({ "n", "v" }, "<leader>dk", dapview.hover, { desc = "Debug: hover value" })
vim.keymap.set("n", "<leader>dv", dapview.virtual_text_toggle, { desc = "Debug: toggle virtual text" })
vim.keymap.set("n", "<leader>du", dapview.toggle, { desc = "Debug: toggle UI" })

require("nvim-treesitter").install({
  "c",
  "cpp",
  "java",
  "python",
  "nix",
})
vim.api.nvim_create_autocmd("FileType", {
  pattern = { "c", "cpp", "java", "python", "nix" },
  callback = function()
    vim.treesitter.start()
  end,
})

vim.keymap.set("n", "<leader>cd", ":cd %:p:h<CR>", { desc = "Change to current directory of file" })
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
    vim.hl.on_yank({ higroup = "IncSearch", timeout = 200 })
  end,
})
