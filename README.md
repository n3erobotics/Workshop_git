# Git-ws

## Introdução

Bem vindo ao workshop de Git organizado pelo N3E.

### Objetivos

Depois deste workshop, vais saber:

0) Criar uma chave SSH e adicionar ao GitHub
1) Usar `git clone` para criar uma cópia local do respositório
2) Ver os branches existentes com `git branch`
3) Criar um branch com `git switch`
4) Usar `git add` e `git commit` para guardar modificações ao código
5) Enviar o commit para o GitHub com `git push`
6) Juntar dois branches com `git merge`
7) Atualizar o respositório local com `git pull`

## 0. Criar uma chave SSH e adicionar ao GitHub

Para poder comunicar com o GitHub, é preciso dar ao git uma maneira de provar quem é que o está a usar. Para isso, usamos as chaves SSH.
Estas chaves não são usadas só para o git, pelo que as ferramentas que as criam são uteis em varias situações. Hoje só vamos ver o que é preciso para por o git a funcionar.  

### Criar a chave

Quem já tem uma chave, que usou no GitLab para IAED por exemplo, pode passar este passo à frente.

O primeiro passo é gerar a chave. Para isso, usamos o comando `ssh-keygen`. Este comando tem várias opções, com usos diversos, mas para o nosso caso apenas precisamos de duas.  
A opção `-t <key_type>` permite escolher que tipo de chave SSH queremos, no nosso caso, queremos uma chave `ed25519`, o recomendado pelo GitHub. (TODO: Fact check this) Para além do `-t`, vamos querer usar também a opção `-C <comment>`, que nos permite adicionar um comentário à chave. O GitHub recomenda incluir o endereço de email como comentário.  

Assim o nosso comando final fica:  
`ssh-keygen -t ed25519 -C <email>`

Ao correr o comando, ele vai perguntar onde queremos guardar a nova chave. Por default, o comando sugere um caminho do tipo `/home/<user>/.ssh`, que é o sitio perfeito para a chave. Para aceitar a sugestão, basta carregarem enter sem escrever nada.

Depois de escolher a localização, o comando pergunta se queremos usar uma `passphrase`, que funciona como uma palavra passe para usar a vossa chave. Se quiserem usar esta funcionalidade, sempre que o git comunicar com o GitHub, vão ter de escrever a palavra passe. Se não quiserem usar, basta carregar enter sem escrever nada. Ele pede para repertir a palvra passe, basta carregar enter mais uma vez.

Por fim, ele gera a chave, guarda-a onde indicámos e mostra um esquema da chave. (É giro mas não faz nada de útil)

O próprio GitHub tem um tutorial mais detalhado. Se tiverem interesse, podem vê-lo [aqui](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent).

### Adicionar ao GitHub

Agora que já temos a nossa chave, temos de a adicionar ao GitHub para que ela seja útil.

Para isso, começamos por ir à página das chaves no site do GitHub. Podem aceder carregando [aqui](https://github.com/settings/keys) ou carregando na vossa foto > 'Settings' > 'SSH and GPG keys'.
Uma vez na página, carregem em 'New SSH key'. Vai aparecer uma nova página com espaço para um título, para a pŕopria chave e um seletor de tipo de chave. Não se preocupem com o tipo de chave, o default ('Authentication Key') é o que precisamos.  
O título é simplesmente o nome que vão dar à chave. Se tiverem mais do que um computador ou tiverem dual boot, dá jeito distinguir as chaves com um título claro.

No campo da chave em sí, vamos ter de ir buscar os conteudos do ficheiro que gerámos no passo anterior. Se tiverem aceite a localização default ao gerar a chave, ela vai estar em `~/.ssh/id_ed25519.pub`. Se ainda tiverem o terminal aberto, podem usar o comando `cat <nome_do_ficheiro>` para ver o conteudo da chave. No caso, usaríamos `cat ~/.ssh/id_ed25519.pub`.  
Se tudo correu bem, deve aparecer no terminal algo do estilo:  
`ssh-ed25519 <texto_estranho> <email>`  
Copiem esta linha toda (no terminal pode ficar divida em mais de uma linha) e ponham no campo 'Key' no site do GitHub. Agora é só clicar em 'Add SSH Key' e está tratado.

Podem ver também o tutorial oficial do GitHub [aqui](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/adding-a-new-ssh-key-to-your-github-account).

## 1. git clone

Para começar a trabalhar com o repositório, precisam de o clonar para o vosso computador. O comando git clone serve para fazer uma cópia local do repositório remoto que está no GitHub.

O comando `git clone <link>` serve exatamente para isto. Podem obter o link no site do repositório, carregando em 'Code' > 'SSH' e copiando o link que aparece.

O repositório vai ser posto numa pasta nova, com o mesmo nome do próprio, na localização onde o terminal estava a correr.

## 2. git branch

Depois de clonarem o repositório, podem verificar as branches existentes. Uma branch é como uma linha de desenvolvimento independente onde fazem alterações.

O comando `git branch` mostra-vos os branches que têm na vossa cópia local do repositório. Para verem também os que existem no GitHub, podem adicionar `-a` (short para `--all`).

Com o `git branch -a` devem conseguir ver pelo menos um `master` e 3 que começam com `remotes/origin`, que são os que existem no GitHub.

## 3. git switch

Para mudar de branch, usam o comando git switch. Isto é importante para trabalhar em funcionalidades diferentes sem alterar diretamente o código principal. Este comando permite-nos não só mudar de branch, mas também criar branches novos.

O comando `git switch <branch>` muda o branch para um branch existente. Se quiserem criar um novo para trabalhar, podem usar `git switch -c <branch>`.

Por agora, criem um branch com o vosso número.

## 4. git add & git commit

## 5. git push

## 6. git merge

## 7. git pull
