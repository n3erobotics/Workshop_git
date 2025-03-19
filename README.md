# Git-ws

## Introdução

Bem vindo ao workshop de Git organizado pelo N3E.

### Objetivos

Depois deste workshop, vais saber:

0) Criar uma chave SSH e adicionar ao gitlab
1) Usar `git clone` para criar uma cópia local do respositório
2) Ver os branches existentes com `git branch`
3) Criar um branch com `git switch`
4) Usar `git add` e `git commit` para guardar modificações ao código
5) Enviar o commit para o gitlab com `git push`
6) Juntar dois branches com `git merge`
7) Atualizar o respositório local com `git pull`

## 0. Criar uma chave SSH e adicionar ao gitlab

Para poder comunicar com o gitlab, é preciso dar ao git uma maneira de provar quem é que o está a usar. Para isso, usamos as chaves SSH.
Estas chaves não são usadas só para o git, pelo que as ferramentas que as criam são uteis em varias situações. Hoje só vamos ver o que é preciso para por o git a funcionar.  

### Criar a chave

O primeiro passo é gerar a chave. Para isso, usamos o comando `ssh-keygen`. Este comando tem várias opções, com usos diversos, mas para o nosso caso apenas precisamos de duas.  
A opção `-t <key_type>` permite escolher que tipo de chave SSH queremos, no nosso caso, queremos uma chave `ed25519`, o recomendado pelo GitHub. (TODO: Fact check this) Para além do `-t`, vamos querer usar também a opção `-C <comment>`, que nos permite adicionar um comentário à chave. O GitHub recomenda incluir o endereço de email como comentário.  

Assim o nosso comando final fica:  
`ssh-keygen -t ed25519 -C <email>`

Ao correr o comando, ele vai perguntar onde queremos guardar a nova chave. Por default, o comando sugere um caminho do tipo `/home/<user>/.ssh/id_ed25519`, que é o sitio perfeito para a chave. Para aceitar a sugestão, basta carregarem enter sem escrever nada.

Depois de escolher a localização, o comando pergunta se queremos usar uma `passphrase`, que funciona como uma palavra passe para usar a vossa chave. Se quiserem usar esta funcionalidade, sempre que o git comunicar com o gitlab, vão ter de escrever a palavra passe. Se não quiserem usar, basta carregar enter sem escrever nada. Ele pede para repertir a palvra passe, basta carregar enter mais uma vez.

Por fim, ele gera a chave, guarda-a onde indicámos e mostra um esquema da chave. (É giro mas não faz nada de útil)

### Adicionar ao gitlab

Agora que já temos a nossa chave, temos de a adicionar ao gitlab para que ela seja útil.

## 1. git clone

## 2. git branch

## 3. git switch

## 4. git add & git commit

## 5. git push

## 6. git merge

## 7. git pull
