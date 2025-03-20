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

Depois de clonarem o repositório, podem verificar as branches existentes. Uma branch é uma "biforcação" da história do desenvolvimento do vosso projeto, isto é, uma linha de desenvolvimento independente, mas com um ponto em comum.

O comando `git branch` mostra-vos os branches que têm na vossa cópia local do repositório. Para verem também os que existem no GitHub, podem adicionar `-a` (short para `--all`).

Com o `git branch -a` devem conseguir ver pelo menos um `master` e 3 que começam com `remotes/origin`, que são os que existem no GitHub.

Também podem utilizar o `git branch` para criar um novo branch, por exemplo: `git branch ist1xxxxxx`.

## 3. git switch

Para mudar de branch, usam o comando git switch. Isto é importante para trabalhar em funcionalidades diferentes sem alterar diretamente o código principal. Este comando permite-nos mudar de branch.

O comando `git switch <branch>` muda o branch para um branch existente.

Também podem utilizar o switch para criar o branch para que querem mudar, com a flag `-c <novo-branch>`. Exemplo: `git switch -c ist1xxxxxx`. Este comando é equivalente a `git branch ist1xxxxxx` seguido de `git switch ist1xxxxxx`.

Por agora, criem um branch com o vosso número!

## 4. git add & git commit

Neste momento já estão na vossa história, podem alterar o vosso projeto sem ter medo de perder o "checkpoint".

Criem um ficheiro qualquer, por exemplo `test.txt`.

Depois de o criarem, podem reparar, utilizando o `git status`, que o git consegue ver que há uma alteração em relação ao último commit ou "checkpoint".

Agora querem criar um novo "checkpoint" com este novo ficheiro. O comando `git commit` cria o tal "checkpoint", mas primeiro têm de lhe dizer o que é que ele deve adicionar ao "checkpoint", porque podem ter criado ficheiros ou feito outras alterações que não querem que conte para o projeto.

Executando o `git add test.txt`, estão a dizer ao git para contar com a alteração para o próximo commit.

Agora, executem `git commit`.

Vai-vos aparecer um editor à frente para escreverem uma descrição do commit, por exemplo `create test.txt`.
Guardem e fechem o editor (assumindo que estão a utilizar `nano`, o editor default do git, façam: `CTRL+X, Y, Enter`).

Pronto! Agora têm um novo checkpoint no vosso projeto!

Podem ver com o `git status` que não têm alterações em relação ao último commit e podem ver com o `git log --graph --all` o histórico dos commits do projeto.

## 5. git merge

Agora vem um comando mais complicado... o `git merge`.

Criaste um branch novo para experimentar adicionar uma feature ao teu projeto, sem correr o risco de "rebentar" com o trabalho todo que já tinhas feito. Ao fim duns dias a bater com a cabeça na parede, está a funcionar! Já é seguro aplicar esse trabalho à versão principal do projeto.

Isso faz-se com o `git merge`. Esse comando faz "replay" dos vossos commits do branch que lhe indicares.

Faz `git switch master` e, de seguida, `git merge ist1xxxxxx`. Isto faz replay dos commit que fizeste no `ist1xxxxxx` no `master`.

Esta storyline

... --- `último commit` (`master`)
                       \
                        `create test.txt` (`ist1xxxxxx`)

Passa a esta

... --- `último commit` ----------------- `create test.txt` (`master`)
                       \                 /
                        `create test.txt`                   (`ist1xxxxxx`)

Neste caso é um merge simples, copia a storyline dum para o outro.

---

Um exemplo mais complicado...

Imagina os commits X, A e B dispostos na seguinte storyline:

`X`             (`master`)
   \
    ----- `A`   (`feature-1`)
     \
      --- `B`   (`feature-2`)

Ambos os commits A e B foram feitos sobre o commit X. Se fizemos `git merge feature-1` seguido de `git merge feature-2`:

`X` --------------- `A` --- `B'`     (`master`)
   \               /       /
    ----- `A` -----       /          (`feature-1`)
     \                   /
      ------- `B` -------            (`feature-2`)

Se cada branch fizer alterações a ficheiros diferentes, ele consegue automaticamente fazer replay do `B` sobre o `A`, mas tecnicamente é um commit diferente, porque é uma base diferente. O `git` é vosso amigo e muda a base do `B` por vocês (para o fazer manualmente, utilizariam o `git rebase`, que não vou explorar aqui, mas recomendo que o investiguem).

No caso em que alteram os dois commits alteram o mesmo ficheiro, o `git` vai pedir-te ajuda para resolver os conflitos. Um dia aprenderão a fazê-lo, a bem ou a mal :)

## 6. git push

No início, replicaram o nosso projeto no GitHub com o `git clone`, certo?
Agora, podem atualizar a réplica remota com a história da vossa réplica local com o `git push`.

Provavelmente vai-vos mostrar este erro: `fatal: The current branch ist1xxxxxx has no upstream branch.`

Isto acontece porque replicaram o projeto, tecnicamente não é o mesmo, o vosso novo branch não tem nenhuma réplica remota associada.
Façam como o `git` sugeriu: `git push --set-upstream origin ist1xxxxxx`.

A partir daqui, podem só utilizar simplesmente `git push` e `git pull` neste branch.

Alternativamente, podem executar `git config push.autoSetupRemote true` para o `git push` fazer isto automaticamente para qualquer branch que criem, ou podem executar `git config --global push.autoSetupRemote true`, para aplicar essa configuração a todos os projetos git que tens ou venhas a ter.

## 7. git pull

O `git pull` é o inverso do `git push`: vai à réplica remota buscar novos commits para o branch atual. Isto é, assumindo que estás no branch `master`, o `git` vai buscar updates ao branch `master` remoto e aplica-os no teu `master` local.

O `git pull --all`, faz `git pull` em todos os branches.
