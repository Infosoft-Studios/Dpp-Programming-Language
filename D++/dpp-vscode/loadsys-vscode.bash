cd dpp-vscode
npm init -y
npm install --save-dev @vscode/vsce
npx vsce package
code --install-extension *.vsix
