t = {}; // objeto árvore

var Tree = function () {/*this.left;this.right;this.key;*/ }
Tree.prototype.isEmpty = function (t) {
    return t.key == undefined;
}
Tree.prototype.insert = function (t, k) {
    if (this.isEmpty(t)) { // critério de parada  
        t.key = k; // se estiver vazio, apenas cria um nodo e 'seta' os lados esquerdo e direito para NULL
        t.left = {};
        t.right = {};
        return true;
    }
    else {
        if (k == t.key) return false;
        if (k < t.key)
            return this.insert(t.left, k);
        else
            return this.insert(t.right, k);
    }
}
Tree.prototype.search = function (t, k) { // pesquisa a chave k na árvore e retorna o nodo da sub-árvore
    if (!isEmpty(t)) {
        if (t.key == k) { // condição de parada
            return t;
        } if (k < t.key) {
            return this.search(t.left, k);
        } else {
            return this.search(t.right, k);
        }
    }
    return undefined;
}

Tree.prototype.AnotherSearch = function (t, k) {
    if (this.isEmpty(t)) return undefined;
    if (t.key == k) return t;
    if (k < t.key) return this.AnotherSearch(t.left, k);
    else return this.AnotherSearch(t.right, k);
}
Tree.prototype.reset = function () { // reseta a árvore
    return {};
}
Tree.prototype.getLeafNumber = function (t) { // retorna o número de nodos folha
    if (!this.isEmpty(t)) {
        if (this.isEmpty(t.left) && this.isEmpty(t.right)) return 1; // critério de parada
        if (this.isEmpty(t.left) && !this.isEmpty(t.right) || this.isEmpty(t.right) && !this.isEmpty(t.left)) return 1;
        return this.getLeafNumber(t.left) + this.getLeafNumber(t.right); // soma recursivamente
    }
    return 1;
}

Tree.prototype.getNotLeafNumber = function (t) { // retorna o número de nodos não folha
    if (!this.isEmpty(t)) {
        if (!this.isEmpty(t.left) && !this.isEmpty(t.right)) // critério de parada
            if (this.isEmpty(t.left) && !this.isEmpty(t.right) || this.isEmpty(t.right) && !this.isEmpty(t.left)) return 1;
    }
    return 1;
}

Tree.prototype.getHeight = function (t) { // retorna a altura da árvore ABP
    if (!this.isEmpty(t)) {
        he = this.getHeight(t.left);
        hd = this.getHeight(t.right);
        if (he < hd) return hd + 1;
        else return he + 1;
    }
    return -1;
}

Tree.prototype.interactiveSearch = function (t, k) { // busca interativa
    if (!this.isEmpty(t)) {
        aux = t;
        if (k == t.key) return t;
        while (k != aux.key && aux != undefined) {
            if (k < aux.key) {
                aux = aux.left;
            } else {
                aux = aux.right;
            }
            if (aux == undefined) return undefined;
        }
        return aux;
    }
}

Tree.prototype.getLowestKey = function (t, l = 99999) { // retorna a menor chave
    if (!this.isEmpty(t)) {
        if (t.key < l) {
            l = t.key;
            return this.getLowestKey(t.left, l);
        }
    }
    return l;
}

Tree.prototype.isAVL = function (t) {
    if (this.isEmpty(t)) return false;
    if (Math.abs(this.getHeight(t.right) - this.getHeight(t.left)) > 1) return false;
    else {
        this.isAVL(t.left);
        this.isAVL(t.right);
    }
    return true;
}


Tree.prototype.getBiggestKey = function (t, b = 0) { // retorna a maior chave
    if (!this.isEmpty(t)) {
        if (t.key > b) {
            b = t.key;
            return this.getBiggestKey(t.right, b);
        }
    }
    return b;
}
Tree.prototype.isDegenerate = function (t) { // verifica se a árvore é degenerada
    if (!this.isEmpty(t.right) && !this.isEmpty(t.left)) return false;
    if (this.isEmpty(t.left) && !this.isEmpty(t.right)) {
        return this.isDegenerate(t.right);
    }
    if (!this.isEmpty(t.left) && this.isEmpty(t.right)) {
        return this.isDegenerate(t.left);
    }
    return true;
}

Tree.prototype.getDiff = function (a, b) { // retorna a diferença entre A e B
    return a - b;
}

Tree.prototype.getPredecessor = function (t, k) { // retorna o nodo antecessor de: um nodo com a chave k
    if (!this.isEmpty(t)) {
        aux = t;
        father = aux;
        while (k != aux.key && aux.key != undefined) {
            if (k < aux.key) {
                father = aux;
                aux = aux.left;
            } else {
                father = aux;
                aux = aux.right;
            }
            if (aux == undefined) return undefined;
        }
        if (k != aux.key) return undefined;
        return father;
    }
}

Tree.prototype.listEvenNumber = function (t) { // retorna os números pares na lista
    if (!this.isEmpty(t)) {
        if (t.key % 2 == 0) console.log(t.key);
        this.listEvenNumber(t.left);
        this.listEvenNumber(t.right);
    }
}
Tree.prototype.isSimetric = function (t, u) { // verifica se duas árvores (t, u) são simétricas
    return ((t.key == undefined && u.key == undefined) ||
        (t.key != undefined && u.key != undefined) &&
        (t.key == u.key) &&
        (this.isSimetric(t.right, u.left)) &&
        (this.isSimetric(u.right, t.left))
    );
}

Tree.prototype.onlyEvenNumber = function (t) {
    if (!this.isEmpty(t)) {
        if (t.key % 2 != 0) console.log(t.key);
        this.onlyEvenNumber(t.left);
        this.onlyEvenNumber(t.right);
    }
}

Tree.prototype.unit = function(t){
    if(!this.isEmpty(t)){
        if(this.isEmpty(t.left) && !this.isEmpty(t.right) || this.isEmpty(t.right) && !this.isEmpty(t.left)) return 1;
        return this.unit(t.left) + this.unit(t.right);
    }
}


/*percursos*/
Tree.prototype.inOrder = function (t) { // faz o percurso da árvore em ordem e mostra as chaves no console
    if (!this.isEmpty(t)) {
        this.inOrder(t.left);
        console.log(t.key);
        this.inOrder(t.right);
    }
}
Tree.prototype.preOrder = function (t) { // faz o percurso da árvore pré ordem e mostra as chaves no console
    if (!this.isEmpty(t)) {
        console.log(t.key);
        this.preOrder(t.left);
        this.preOrder(t.right);
    }
}
Tree.prototype.posOrder = function (t) { // faz o percurso da árvore pós ordem e mostra as chaves no console
    if (!this.isEmpty(t)) {
        this.preOrder(t.left);
        this.preOrder(t.right);
        console.log(t.key);
    }
}

Tree.prototype.decrescente = function (t) { // faz o percurso da árvore e mostra as chaves no console decrescente
    if (!this.isEmpty(t)) {
        this.decrescente(t.right);
        console.log(t.key);
        this.decrescente(t.left);
    }
}